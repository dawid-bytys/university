import { Form, FieldArray, useFormik, Field, FormikProvider } from 'formik';
import { useRef, useState } from 'react';
import { uploadImage } from '../domain/cloudinary';
import { Loading } from '../components/Loading';
import clsx from 'clsx';
import { fetchGeolocation } from '../domain/ninja';
import { addJob } from '../domain/jobs';
import { resizeImage } from '../utils';

const initialValues = {
  title: '',
  description: '',
  location: '',
  salary: {
    from: '',
    to: '',
    currency: 'PLN',
  },
  tags: [],
  requirements: [],
  benefits: [],
  company: '',
  image: '',
  typeOfWork: 'Full-time',
  seniority: 'Junior',
  employment: 'B2B',
  operatingMode: 'Remote',
};

export function AddJobPage() {
  const formik = useFormik({
    initialValues,
    validate: handleValidation,
    onSubmit: handleSubmit,
    validateOnChange: false,
    validateOnBlur: false,
  });
  const { setFieldError, handleBlur, isSubmitting, values, errors } = formik;
  const imageRef = useRef(null);
  const [image, setImage] = useState(null);
  const [submittionState, setSubmittionState] = useState({
    state: 'idle',
    message: '',
  });

  function handleValidation(values) {
    const errors = {};

    if (!values.title) {
      errors.title = 'Title is required!';
    }

    if (!values.description) {
      errors.description = 'Description is required!';
    }

    if (!values.location) {
      errors.location = 'Location is required!';
    }

    if (!values.salary.from || !values.salary.to) {
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

  function handleImageChange(e) {
    const file = e.target.files[0];

    const validImageTypes = ['image/jpeg', 'image/png'];
    if (!validImageTypes.includes(file.type)) {
      setFieldError('image', 'File must be an image!');
      return;
    }

    if (file.size > 5242880) {
      setFieldError('image', 'File size must be less than 5MB!');
      return;
    }

    const image = new Image();
    image.src = URL.createObjectURL(file);

    image.onload = () => {
      const { width, height } = image;

      if (width < 256 || height < 256) {
        setFieldError('image', 'Image size must be at least 256x256px!');
        return;
      }

      if (width !== height) {
        setFieldError('image', 'Image must be square!');
        return;
      }

      setImage(file);
    };
  }

  async function handleSubmit() {
    try {
      const resizedImage = await resizeImage(image);
      const imageUrl = await uploadImage(resizedImage);
      const geolocation = await fetchGeolocation(values.location);

      const serializedValues = {
        ...values,
        requirements: values.requirements.filter((requirement) => requirement.trim() !== ''),
        benefits: values.benefits.filter((benefit) => benefit.trim() !== ''),
        tags: values.tags.split(',').map((tag) => tag.trim()),
        image: imageUrl,
        location: geolocation,
      };

      console.log(serializedValues);

      const response = await addJob(serializedValues);

      setSubmittionState({
        state: 'success',
        message: response.message,
      });
    } catch (err) {
      setSubmittionState({
        state: 'error',
        message: 'Something went wrong, try again!',
      });
    }
  }

  return (
    <main className="flex flex-1 flex-col items-center gap-7 p-7 md:gap-10 md:p-10 lg:gap-16 lg:p-16">
      <h2 className="text-3xl font-semibold">Add a new job listing</h2>
      <FormikProvider value={formik}>
        <Form
          disabled={isSubmitting}
          className={clsx({
            'flex flex-col gap-7 font-medium w-full md:w-3/4 2xl:w-1/3': true,
            'opacity-50 pointer-events-none': isSubmitting,
          })}
        >
          {submittionState.state !== 'idle' && (
            <SubmittionMessage
              isError={submittionState.state === 'error'}
              message={submittionState.message}
            />
          )}
          <div className="flex flex-col gap-2">
            <label htmlFor="company">Company</label>
            <Field
              id="company"
              type="text"
              name="company"
              placeholder="e.g. Microsoft"
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {errors.company && <ErrorMessage message={errors.company} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="title">Title</label>
            <Field
              id="title"
              type="text"
              name="title"
              placeholder="e.g. Senior Frontend Developer"
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {errors.title && <ErrorMessage message={errors.title} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="description">Description</label>
            <Field
              id="description"
              as="textarea"
              name="description"
              placeholder="e.g. We are looking for a Senior Frontend Developer to join our team."
              className="border-2 border-gray-300 rounded-md p-3 resize-none h-40"
            />
            {errors.description && <ErrorMessage message={errors.description} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="requirements">Requirements</label>
            <FieldArray
              name="requirements"
              id="requirements"
            >
              {({ remove, push }) => (
                <>
                  {values.requirements.map((_, index) => (
                    <div
                      className="flex flex-row gap-2"
                      key={`requirement-${index}`}
                    >
                      <Field
                        name={`requirements.${index}`}
                        type="text"
                        placeholder="e.g. 5+ years of experience"
                        className="w-full border-2 border-gray-300 rounded-md p-3"
                      />
                      <button
                        type="button"
                        className="rounded-md aspect-square text-center text-white bg-red-500"
                        onClick={() => remove(index)}
                      >
                        -
                      </button>
                    </div>
                  ))}
                  <button
                    type="button"
                    className="rounded-md py-3 text-center text-white bg-primary"
                    onClick={() => push('')}
                  >
                    +
                  </button>
                </>
              )}
            </FieldArray>
            {errors.requirements && <ErrorMessage message={errors.requirements} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="benefits">Benefits</label>
            <FieldArray
              name="benefits"
              id="benefits"
            >
              {({ remove, push }) => (
                <>
                  {values.benefits.map((_, index) => (
                    <div
                      className="flex flex-row gap-2"
                      key={`benefits-${index}`}
                    >
                      <Field
                        name={`benefits.${index}`}
                        type="text"
                        placeholder="e.g. Free lunch"
                        className="w-full border-2 border-gray-300 rounded-md p-3"
                      />
                      <button
                        type="button"
                        className="rounded-md aspect-square text-center text-white bg-red-500"
                        onClick={() => remove(index)}
                      >
                        -
                      </button>
                    </div>
                  ))}
                  <button
                    type="button"
                    className="rounded-md py-3 text-center text-white bg-primary"
                    onClick={() => push('')}
                  >
                    +
                  </button>
                </>
              )}
            </FieldArray>
            {errors.benefits && <ErrorMessage message={errors.benefits} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="location">Location</label>
            <Field
              id="location"
              type="text"
              name="location"
              placeholder="e.g. Berlin"
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {errors.location && <ErrorMessage message={errors.location} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="salary">Salary</label>
            <div className="flex flex-col xl:flex-row gap-2">
              <FieldArray
                name="salary"
                id="salary"
              >
                <>
                  <div className="flex flex-col xl:flex-row gap-2 flex-1">
                    <Field
                      type="number"
                      name="salary.from"
                      placeholder="from"
                      className="border-2 border-gray-300 rounded-md p-3 xl:basis-1/2"
                    />
                    <Field
                      type="number"
                      name="salary.to"
                      placeholder="to"
                      className="border-2 border-gray-300 rounded-md p-3 xl:basis-1/2"
                    />
                  </div>
                  <Field
                    as="select"
                    placeholder="from"
                    selected="PLN"
                    name="salary.currency"
                    className="bg-transparent border-2 border-gray-300 rounded-md p-3"
                  >
                    {['PLN', 'EUR', 'USD'].map((currency) => (
                      <option
                        key={currency}
                        value={currency}
                      >
                        {currency}
                      </option>
                    ))}
                  </Field>
                </>
              </FieldArray>
            </div>
            {errors.salary && <ErrorMessage message={errors.salary} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="typeOfWork">Type of work</label>
            <Field
              id="typeOfWork"
              as="select"
              name="typeOfWork"
              selected="Full-time"
              className="bg-transparent border-2 border-gray-300 rounded-md p-3"
            >
              {['Full-time', 'Part-time'].map((typeOfWork) => (
                <option
                  key={typeOfWork}
                  value={typeOfWork}
                >
                  {typeOfWork}
                </option>
              ))}
            </Field>
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="seniority">Seniority</label>
            <Field
              as="select"
              name="seniority"
              selected="Junior"
              className="bg-transparent border-2 border-gray-300 rounded-md p-3"
            >
              {['Junior', 'Regular', 'Senior', 'Trainee'].map((seniority) => (
                <option
                  key={seniority}
                  value={seniority}
                >
                  {seniority}
                </option>
              ))}
            </Field>
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="employment">Employment type</label>
            <Field
              id="employment"
              as="select"
              name="employment"
              selected="Junior"
              className="bg-transparent border-2 border-gray-300 rounded-md p-3"
            >
              {['UoP', 'UoZ', 'UoG', 'B2B'].map((employment) => (
                <option
                  key={employment}
                  value={employment}
                >
                  {employment}
                </option>
              ))}
            </Field>
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="operatingMode">Operating mode</label>
            <Field
              id="operatingMode"
              as="select"
              name="operatingMode"
              selected="Remote"
              className="bg-transparent border-2 border-gray-300 rounded-md p-3"
            >
              {['Remote', 'Hybrid', 'Office'].map((operatingMode) => (
                <option
                  key={operatingMode}
                  value={operatingMode}
                >
                  {operatingMode}
                </option>
              ))}
            </Field>
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="tags">Tags</label>
            <Field
              type="text"
              name="tags"
              placeholder="e.g. frontend, react, javascript"
              className="border-2 border-gray-300 rounded-md p-3"
            />
            {errors.tags && <ErrorMessage message={errors.tags} />}
          </div>
          <div className="flex flex-col gap-2">
            <label htmlFor="image">Logo</label>
            <input
              type="file"
              name="image"
              onChange={handleImageChange}
              onBlur={handleBlur}
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
            {errors.image && <ErrorMessage message={errors.image} />}
          </div>
          <button
            type="submit"
            className="flex items-center justify-center rounded-md h-[48px] text-center text-white bg-primary"
          >
            {isSubmitting ? (
              <Loading
                spinnerWidth={20}
                spinnerHeight={20}
                color="#fff"
              />
            ) : (
              'Submit'
            )}
          </button>
        </Form>
      </FormikProvider>
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

function SubmittionMessage({ isError, message }) {
  return (
    <div
      className={clsx({
        'flex items-center justify-center rounded-md h-[48px] text-center bg-opacity-80': true,
        'text-white bg-[#2eff7c]': !isError,
        'text-white bg-red-500': isError,
      })}
    >
      <p className="text-md">{message}</p>
    </div>
  );
}
