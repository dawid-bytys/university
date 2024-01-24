import { Formik, useFormik } from 'formik';
import { useRef, useState } from 'react';
import { uploadImage } from '../domain/cloudinary';
import { Loading } from '../components/Loading';

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
  const [isImageUploading, setIsImageUploading] = useState(false);

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

    if (!values.image) {
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

  function handleAddRequirement(e) {
    e.preventDefault();
    formikProps.setFieldValue('requirements', [...formikProps.values.requirements, '']);
  }

  function handleAddBenefit(e) {
    e.preventDefault();
    formikProps.setFieldValue('benefits', [...formikProps.values.benefits, '']);
  }

  function handleRemoveRequirement(e, requirementIndex) {
    e.preventDefault();
    formikProps.setFieldValue(
      'requirements',
      formikProps.values.requirements.filter((_, index) => index !== requirementIndex),
    );
  }

  function handleRemoveBenefit(e, benefitIndex) {
    e.preventDefault();
    formikProps.setFieldValue(
      'benefits',
      formikProps.values.benefits.filter((_, index) => index !== benefitIndex),
    );
  }

  function handleRequirementChange(e, requirementIndex) {
    e.preventDefault();
    formikProps.setFieldValue(
      'requirements',
      formikProps.values.requirements.map((requirement, index) =>
        index === requirementIndex ? e.target.value.trim() : requirement,
      ),
    );
  }

  function handleBenefitChange(e, benefitIndex) {
    e.preventDefault();
    formikProps.setFieldValue(
      'benefits',
      formikProps.values.benefits.map((benefit, index) =>
        index === benefitIndex ? e.target.value.trim() : benefit,
      ),
    );
  }

  async function handleSubmit() {
    formikProps.values = {
      ...formikProps.values,
      requirements: formikProps.values.requirements.filter((requirement) => requirement !== ''),
      benefits: formikProps.values.benefits.filter((benefit) => benefit !== ''),
      tags: formikProps.values.tags.split(',').map((tag) => tag.trim()),
    };

    console.log(formikProps.values);
  }

  async function handleImageChange(e) {
    const file = e.target.files[0];

    if (!file.type.startsWith('image/')) {
      formikProps.setFieldError('image', 'File must be an image!');
      return;
    }

    setIsImageUploading(true);
    const imageUrl = await uploadImage(file);
    setIsImageUploading(false);
    formikProps.setFieldValue('image', imageUrl);
  }

  return (
    <main className="flex flex-1 flex-col items-center gap-7 p-7 md:gap-10 md:p-10 lg:gap-16 lg:p-16">
      <h2 className="text-3xl font-semibold">Add a new job listing</h2>
      <Formik formikProps={formikProps}>
        <form
          onSubmit={formikProps.handleSubmit}
          className="flex flex-col gap-7 w-full font-medium md:w-3/4 lg:w-1/2"
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
                  onClick={(e) => handleRemoveRequirement(e, index)}
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
                  onClick={(e) => handleRemoveBenefit(e, index)}
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
              {isImageUploading ? (
                <Loading />
              ) : formikProps.values.image ? (
                <img
                  src={formikProps.values.image}
                  alt="Logo"
                  className="w-40 h-40 object-contain"
                />
              ) : (
                'Upload logo'
              )}
            </button>
            {formikProps.errors.image && <ErrorMessage message={formikProps.errors.image} />}
          </div>
          <button
            type="submit"
            className="rounded-md px-5 py-3 text-center text-white bg-primary"
            disabled={formikProps.isSubmitting || isImageUploading}
          >
            Submit
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
