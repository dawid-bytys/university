import { isNewOffer } from '../utils';
import heartSvg from '../assets/svg/heart.svg';
import clsx from 'clsx';

export function JobOffer({
  image,
  company,
  title,
  location,
  tags,
  salary,
  createdAt,
  isSingleOffer = false,
}) {
  return (
    <article
      className={clsx({
        'flex flex-col md:flex-row gap-5 w-full': true,
        'shadow hover:border-primary hover:transition-colors border-2 border-neutral-200 p-5 rounded-xl':
          !isSingleOffer,
      })}
    >
      <div className="aspect-square w-24 h-24 md:w-36 md:h-36">
        <img
          src={image}
          alt={company}
          className="w-full h-full rounded-md"
        />
      </div>
      <div className="flex flex-1 flex-col w-full justify-between gap-3 sm:gap-2">
        <div className="flex flex-row gap-3 items-center">
          <p className="text-[#8395A2] text-xl font-medium">{company}</p>
          {isNewOffer(createdAt) && <New />}
        </div>
        <div className="flex flex-col gap-3 sm:flex-row justify-between">
          <p className="font-medium text-xl">{title}</p>
          <p className="flex flex-row items-center gap-2 text-xl font-medium text-primary">
            {salary.from} - {salary.to} {salary.currency}
          </p>
        </div>
        <div>
          <p className="text-[#CFD6E0]">{location.city}</p>
        </div>
        <div className="flex flex-col gap-3 sm:flex-row justify-between">
          <div className="flex flex-row gap-2 flex-wrap">
            {tags.map((tag, index) => (
              <Tag
                key={index}
                text={tag}
              />
            ))}
          </div>
          <time className="flex items-center">
            <p className="text-[#CFD6E0] text-center">
              {new Date(createdAt).toISOString().split('T')[0]}
            </p>
          </time>
        </div>
      </div>
    </article>
  );
}

function Tag({ text }) {
  return (
    <div className="bg-neutral-100 rounded-md p-2 flex items-center justify-center">
      <p className="text-gray-400 text-sm">{text}</p>
    </div>
  );
}

function New() {
  return (
    <div className="flex flex-row items-center p-1 px-2 gap-2 bg-[#EFEBFD] rounded-sm">
      <img
        src={heartSvg}
        alt="New"
        className="w-3 h-3"
      />
      <p className="text-primary text-sm">New</p>
    </div>
  );
}
