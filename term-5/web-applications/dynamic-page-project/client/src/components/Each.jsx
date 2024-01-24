export function Each({ of, render }) {
  return of.map(render);
}
