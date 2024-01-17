export function errorMiddleware(err, _req, res, next) {
  try {
    next(err);
  } catch (err) {
    res.status(500).json({
      message: 'Unexpected error occurred.',
    });
  }
}
