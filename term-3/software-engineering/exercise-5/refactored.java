class ReportCatalogueIndexCommandParser {
    static final String NO_GROUPING = "orgNoGrouping";
    static final int ORG_CATALOG = 0;
    static final int PART_CATALOG = 1;

    int getGroupingType(final String grouping) throws IllegalArgumentException {
        if (grouping.equals(NO_GROUPING) || grouping.equals("orgGroupByCountry")
                || grouping.equals("orgGroupByTypeOfOrgName")) {
            return ORG_CATALOG;
        }
        if (grouping.equals("part")) {
            return PART_CATALOG;
        }
        throw new IllegalArgumentException("Invalid grouping!");
    }
}