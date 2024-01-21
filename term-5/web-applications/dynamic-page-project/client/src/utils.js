export function isNewOffer(date) {
  return new Date(date) > new Date(Date.now() - 7 * 24 * 60 * 60 * 1000);
}

export function randomGradient() {
  const gradients = [
    'bg-gradient-to-r from-pink-500 via-red-500 to-yellow-500',
    'bg-gradient-to-r from-green-300 via-blue-500 to-purple-600',
    'linear-gradient(to right, rgb(254, 249, 195), rgb(253, 224, 71), rgb(234, 179, 8))',
    'bg-gradient-to-r from-green-200 via-green-400 to-green-500',
    'bg-gradient-to-r from-yellow-200 to-yellow-500',
    'bg-gradient-to-r from-blue-700 via-blue-800 to-gray-900',
    'bg-gradient-to-r from-yellow-600 to-red-600',
    'bg-gradient-to-r from-pink-400 to-pink-600',
  ];

  return gradients[Math.floor(Math.random() * gradients.length)];
}
