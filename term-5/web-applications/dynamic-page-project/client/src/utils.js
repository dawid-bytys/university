export function isNewOffer(date) {
  return new Date(date) > new Date(Date.now() - 7 * 24 * 60 * 60 * 1000);
}

export function formatSalary(salary) {
  return salary / 10000;
}
