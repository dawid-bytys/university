abstract class Rental {
    protected String fee;
    protected Date dueDate;
    protected Date rentDate;

    public boolean isOverdue() {
        return dueDate.before(new Date());
    }

    public double getTotalFee() {
        return isOverdue() ? 1.2 * rentalFee : rentalFee;
    }
}

public class BookRental extends Rental {
    private String bookTitle;
    private String author;

    public BookRental(final String bookTitle, final String author, final String fee, final Date dueDate,
            final Date rentDate) {
        this.bookTitle = bookTitle;
        this.author = author;
        this.fee = fee;
        this.dueDate = dueDate;
        this.rentDate = rentDate;
    }
}

public class MovieRental extends Rental {
    private String movieTitle;
    private String classification;

    public MovieRental(final String movieTitle, final String classification, final String fee, final Date dueDate,
            final Date rentDate) {
        this.movieTitle = movieTitle;
        this.classification = classification;
        this.fee = fee;
        this.dueDate = dueDate;
        this.rentDate = rentDate;
    }
}