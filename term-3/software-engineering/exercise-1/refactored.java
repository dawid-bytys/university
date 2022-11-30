class Organization {
	String id;
	String eName;
	String cName;
	Telephone tel;
	Telephone fax;
	ContactPerson contactPerson;
}

class Telephone {
	String countryCode;
	String areaCode;
	String localNumber;
}

class ContactPerson {
	Fullname eName;
	Fullname cName;
	Telephone mob;
	Telephone tel;
	Telephone fax;
}

class Fullname {
	String firstName;
	String lastName;
}