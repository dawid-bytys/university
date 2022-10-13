class Main {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No argument provided!");
            return;
        }

        Pesel examplePesel = new Pesel(args[0]);
        String output = String.format("Is PESEL %s valid?: %b", args[0], examplePesel.isValid());

        System.out.println(output);
    }
}