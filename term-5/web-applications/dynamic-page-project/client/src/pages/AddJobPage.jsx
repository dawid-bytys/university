import { Formik, useFormik } from 'formik';
import { useRef, useState } from 'react';
import { uploadImage } from '../domain/cloudinary';
import { Loading } from '../components/Loading';
import clsx from 'clsx';

const initialValues = {
  title: '',
  description: '',
  location: {
    city: '',
    lat: '',
    lng: '',
  },
  salary: '',
  tags: [],
  requirements: [],
  benefits: [],
  company: '',
  image: '',
};

export function AddJobPage() {
  const formikProps = useFormik({
    initialValues,
    onSubmit: handleSubmit,
    validate: handleValidation,
    validateOnChange: false,
    validateOnBlur: false,
  });
  const imageRef = useRef(null);
  const [image, setImage] = useState(null);

  function handleValidation(values) {
    const errors = {};

    if (!values.title) {
      errors.title = 'Title is required!';
    }

    if (!values.description) {
      errors.description = 'Description is required!';
    }

    if (!values.location.city) {
      errors.location = 'Location is required!';
    }

    if (!values.salary) {
      errors.salary = 'Salary is required!';
    }

    if (values.tags.length === 0) {
      errors.tags = 'Tags are required!';
    }

    if (!values.company) {
      errors.company = 'Company is required!';
    }

    if (!values.image && !image) {
      errors.image = 'Logo is required!';
    }

    if (values.requirements.length === 0) {
      errors.requirements = 'Requirements are required!';
    }

    if (values.benefits.length === 0) {
      errors.benefits = 'Benefits are required!';
    }

    return errors;
  }

  function handleAddRequirement() {
    formikProps.setFieldValue('requirements', [...formikProps.values.requirements, '']);
  }

  function handleAddBenefit() {
    formikProps.setFieldValue('benefits', [...formikProps.values.benefits, '']);
  }

  function handleRemoveRequirement(requirementIndex) {
    formikProps.setFieldValue(
      'requirements',
      formikProps.values.requirements.filter((_, index) => index !== requirementIndex),
    );
  }

  function handleRemoveBenefit(benefitIndex) {
    formikProps.setFieldValue(
      'benefits',
      formikProps.values.benefits.filter((_, index) => index !== benefitIndex),
    );
  }

  function handleRequirementChange(e, requirementIndex) {
    formikProps.setFieldValue(
      'requirements',
      formikProps.values.requirements.map((requirement, index) =>
        index === requirementIndex ? e.target.value.trim() : requirement,
      ),
    );
  }

  function handleBenefitChange(e, benefitIndex) {
    formikProps.setFieldValue(
      'benefits',
      formikProps.values.benefits.map((benefit, index) =>
        index === benefitIndex ? e.target.value.trim() : benefit,
      ),
    );
  }

  function handleImageChange(e) {
    const file = e.target.files[0];

    const validImageTypes = ['image/jpeg', 'image/png'];
    if (!validImageTypes.includes(file.type)) {
      formikProps.setFieldError('image', 'File must be an image!');
      return;
    }

    if (file.size > 5242880) {
      formikProps.setFieldError('image', 'File size must be less than 5MB!');
      return;
    }

    const image = new Image();
    image.src = URL.createObjectURL(file);

    image.onload = () => {
      const { width, height } = image;

      if (width < 256 || height < 256) {
        formikProps.setFieldError('image', 'Image size must be at least 256x256px!');
        return;
      }

      if (width !== height) {
        formikProps.setFieldError('image', 'Image must be square!');
        return;
      }

      setImage(file);
      formikProps.setFieldError('image', null);
    };
  }

  async function handleSubmit() {
    const imageUrl = await uploadImage(image);

    formikProps.values = {
      ...formikProps.values,
      requirements: formikProps.values.requirements.filter((requirement) => requirement !== ''),
      benefits: formikProps.values.benefits.filter((benefit) => benefit !== ''),
      tags: formikProps.values.tags.split(',').map((tag) => tag.trim()),
      image: imageUrl,
    };

    console.log(formikProps.values);
  }

  return (
    <main className="flex flex-1 flex-col items-center gap-7 p-7 md:gap-10 md:p-10 lg:gap-16 lg:p-16">
      <h2 className="text-3xl font-semibold">Add a new job listing</h2>
      <Formik formikProps={formikProps}>
        <form
          onSubmit={formikProps.handleSubmit}
          disabled={formikProps.isSubmitting}
          className={clsx({
            'flex flex-col gap-7 font-medium w-full md:w-3/4 lg:w-1/2': true,
            'opacity-50 pointer-events-none': formikProps.isSubmitting,
          })}
        >
          <div className="flex flex-col gap-2">
            <label htmlFor="company">Company</label>
            <input
              type="text"
              name="company"
              id="company"
              placeholder="e.g. Microsoft"
              value={formikProps.values.company}
              onChange={formikProps.handleChange}
              onBlur={formikProps.handleBlur}
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {formikProps.errors.company && <ErrorMessage message={formikProps.errors.company} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="title">Title</label>
            <input
              type="text"
              name="title"
              id="title"
              placeholder="e.g. Senior Frontend Developer"
              value={formikProps.values.title}
              onChange={formikProps.handleChange}
              onBlur={formikProps.handleBlur}
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {formikProps.errors.title && <ErrorMessage message={formikProps.errors.title} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="description">Description</label>
            <textarea
              name="description"
              id="description"
              placeholder="e.g. We are looking for a Senior Frontend Developer to join our team."
              value={formikProps.values.description}
              onChange={formikProps.handleChange}
              onBlur={formikProps.handleBlur}
              className="border-2 border-gray-300 rounded-md p-3 resize-none h-40"
            />
            {formikProps.errors.description && (
              <ErrorMessage message={formikProps.errors.description} />
            )}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="requirements">Requirements</label>
            {formikProps.values.requirements.map((requirement, index) => (
              <div
                className="flex flex-row gap-2"
                key={`requirement-${index}`}
              >
                <input
                  type="text"
                  name="requirements"
                  id="requirements"
                  placeholder="e.g. 5+ years of experience"
                  value={requirement}
                  onChange={(e) => handleRequirementChange(e, index)}
                  onBlur={formikProps.handleBlur}
                  className="w-full border-2 border-gray-300 rounded-md p-3"
                />
                <button
                  type="button"
                  className="rounded-md aspect-square text-center text-white bg-red-500"
                  onClick={() => handleRemoveRequirement(index)}
                >
                  -
                </button>
              </div>
            ))}
            <button
              type="button"
              className="rounded-md py-3 text-center text-white bg-primary"
              onClick={handleAddRequirement}
            >
              +
            </button>
            {formikProps.errors.requirements && (
              <ErrorMessage message={formikProps.errors.requirements} />
            )}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="benefits">Benefits</label>
            {formikProps.values.benefits.map((benefit, index) => (
              <div
                className="flex flex-row gap-2 w-full"
                key={`benefit-${index}`}
              >
                <input
                  key={`benefit-${index}`}
                  type="text"
                  name="benefits"
                  id="benefits"
                  placeholder="e.g. Free lunch"
                  value={benefit}
                  onChange={(e) => handleBenefitChange(e, index)}
                  onBlur={formikProps.handleBlur}
                  className="w-full border-2 border-gray-300 rounded-md p-3"
                />
                <button
                  type="button"
                  className="rounded-md aspect-square text-center text-white bg-red-500"
                  onClick={() => handleRemoveBenefit(index)}
                >
                  -
                </button>
              </div>
            ))}
            <button
              type="button"
              className="rounded-md py-3 text-center text-white bg-primary"
              onClick={handleAddBenefit}
            >
              +
            </button>
            {formikProps.errors.benefits && <ErrorMessage message={formikProps.errors.benefits} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="location">Location</label>
            <input
              type="text"
              name="location"
              id="location"
              placeholder="e.g. Berlin, Germany"
              value={formikProps.values.location.city}
              onChange={(e) => {
                formikProps.setFieldValue('location', {
                  ...formikProps.values.location,
                  city: e.target.value,
                });
              }}
              onBlur={formikProps.handleBlur}
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {formikProps.errors.location && <ErrorMessage message={formikProps.errors.location} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="salary">Salary</label>
            <input
              type="text"
              name="salary"
              id="salary"
              placeholder="e.g. 60000 - 80000 EUR"
              value={formikProps.values.salary}
              onChange={formikProps.handleChange}
              onBlur={formikProps.handleBlur}
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {formikProps.errors.salary && <ErrorMessage message={formikProps.errors.salary} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="tags">Tags</label>
            <input
              type="text"
              name="tags"
              id="tags"
              placeholder="e.g. frontend, react, javascript"
              value={formikProps.values.tags}
              onChange={formikProps.handleChange}
              onBlur={formikProps.handleBlur}
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {formikProps.errors.tags && <ErrorMessage message={formikProps.errors.tags} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="image">Logo</label>
            <input
              type="file"
              name="image"
              id="image"
              onChange={handleImageChange}
              onBlur={formikProps.handleBlur}
              className="hidden"
              ref={imageRef}
            />
            <button
              type="button"
              className="bg-neutral-100 border-2 border-gray-300 rounded-md border-dashed w-40 h-40 flex items-center justify-center hover:bg-neutral-200 transition-colors"
              onClick={() => imageRef.current.click()}
            >
              {image ? (
                <img
                  src={URL.createObjectURL(image)}
                  alt="logo"
                />
              ) : (
                'Upload logo'
              )}
            </button>
            <p className="text-gray-400">max. 5MB min. 256x256px</p>
            {formikProps.errors.image && <ErrorMessage message={formikProps.errors.image} />}
          </div>
          <button
            type="submit"
            className="flex items-center justify-center rounded-md h-[48px] text-center text-white bg-primary"
          >
            {formikProps.isSubmitting ? (
              <Loading
                spinnerWidth={20}
                spinnerHeight={20}
                color="#fff"
              />
            ) : (
              'Submit'
            )}
          </button>
        </form>
      </Formik>
    </main>
  );
}

function ErrorMessage({ message }) {
  return (
    <p className="text-red-500 text-sm">
      <i>{message}</i>
    </p>
  );
}
