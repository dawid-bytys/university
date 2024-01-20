import heartSvg from '../assets/svg/heart.svg';
import { isNewOffer } from '../utils';

export function JobOffer({ image, company, title, locations, tags, salary, createdAt }) {
  return (
    <article className="flex flex-col md:flex-row gap-5 p-5 shadow rounded-lg border-[1px] border-neutral-200">
      <div className="aspect-square max-w-36 max-h-36 min-w-10 min-h-10">
        <img
          src={image}
          alt={company}
          className="w-full h-full rounded-md"
        />
      </div>
      <div className="flex flex-1 flex-col w-full justify-between gap-3 sm:gap-2">
        <div className="flex flex-row gap-3 items-center">
          <p className="text-[#8395A2] text-xl">{company}</p>
          {isNewOffer(createdAt) && <New />}
        </div>
        <div className="flex flex-col gap-3 sm:flex-row justify-between">
          <p className="font-medium text-xl">{title}</p>
          <p className="flex flex-row items-center gap-2 text-xl font-semibold">
            <span className="text-primary">
              {salary.from / 10000} - {salary.to / 1000}k
            </span>
            <span className="text-[#CFD6E0]">{salary.currency}</span>
          </p>
        </div>
        <div>
          <p className="text-[#CFD6E0]">{locations.join(', ').trimEnd()}</p>
        </div>
        <div className="flex flex-col gap-3 sm:flex-row justify-between">
          <div className="flex flex-row gap-2">
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
