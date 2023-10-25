/** @type {import('tailwindcss').Config} */
export default {
  content: ['./index.html', './src/**/*.{js,ts,jsx,tsx}'],
  theme: {
    extend: {
      colors: {
        primary: '#caff33',
        secondary: '#1a1a1a',
      },
      fontFamily: {
        'poppins-regular': 'Poppins-Regular',
        'poppins-medium': 'Poppins-Medium',
        'poppins-semibold': 'Poppins-SemiBold',
      },
    },
  },
  plugins: [],
};
