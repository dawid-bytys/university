import type { IconProps } from '@/types';

export function LogoIcon({ width, height }: IconProps) {
  return (
    <svg
      width={width || '26'}
      height={height || '27'}
      viewBox="0 0 26 27"
      fill="none"
      xmlns="http://www.w3.org/2000/svg"
    >
      <path
        d="M6.50033 13.6751L13.0003 7.17513L19.5003 13.6751L13.0003 20.1751L6.50033 13.6751Z"
        fill="#CAFF33"
      />
      <path
        d="M23.8337 9.3418L19.5003 13.6751V7.17513H13.0003L17.3337 2.8418H23.8337V9.3418Z"
        fill="#CAFF33"
      />
      <path
        d="M23.8337 18.0085L19.5003 13.6751V20.1751H13.0003L17.3337 24.5085H23.8337V18.0085Z"
        fill="#CAFF33"
      />
      <path
        d="M2.16699 18.0085L6.50033 13.6751V20.1751H13.0003L8.66699 24.5085H2.16699L2.16699 18.0085Z"
        fill="#CAFF33"
      />
      <path
        d="M2.16699 9.3418L6.50033 13.6751V7.17513H13.0003L8.66699 2.8418H2.16699L2.16699 9.3418Z"
        fill="#CAFF33"
      />
    </svg>
  );
}
