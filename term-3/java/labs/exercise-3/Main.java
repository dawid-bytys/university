import java.util.Arrays;

public class Main {
        public static void main(String[] args) {
                // MyInteger
                MyInteger myInteger1 = (MyInteger) new MyInteger().create("5").add(new MyInteger().create("5")); // 10
                MyInteger myInteger2 = (MyInteger) new MyInteger().create("5").sub(new MyInteger().create("5")); // 0
                MyInteger myInteger3 = (MyInteger) new MyInteger().create("5").mul(new MyInteger().create("5")); // 25
                MyInteger myInteger4 = (MyInteger) new MyInteger().create("5").div(new MyInteger().create("5")); // 1
                MyInteger myInteger5 = (MyInteger) new MyInteger().create("5").pow(new MyInteger().create("5")); // 3125

                // MyDouble
                MyDouble myDouble1 = (MyDouble) new MyDouble().create("5.5").add(new MyDouble().create("5.5")); // 11.0
                MyDouble myDouble2 = (MyDouble) new MyDouble().create("5.5").sub(new MyDouble().create("5.5")); // 0.0
                MyDouble myDouble3 = (MyDouble) new MyDouble().create("5.5").mul(new MyDouble().create("5.5")); // 30.25
                MyDouble myDouble4 = (MyDouble) new MyDouble().create("5.5").div(new MyDouble().create("5.5")); // 1.0
                MyDouble myDouble5 = (MyDouble) new MyDouble().create("5.5").pow(new MyDouble().create("5.5")); // 1000.0

                // ImaginaryInt
                ImaginaryInt imaginaryInt1 = (ImaginaryInt) new ImaginaryInt().create("5i")
                                .add(new ImaginaryInt().create("5i")); // 10i
                ImaginaryInt imaginaryInt2 = (ImaginaryInt) new ImaginaryInt().create("5i")
                                .sub(new ImaginaryInt().create("5i")); // 0i
                ImaginaryInt imaginaryInt3 = (ImaginaryInt) new ImaginaryInt().create("5i")
                                .mul(new ImaginaryInt().create("5i")); // -25
                ImaginaryInt imaginaryInt4 = (ImaginaryInt) new ImaginaryInt().create("5i")
                                .div(new ImaginaryInt().create("5i")); // 1

                // ImaginaryDouble
                ImaginaryDouble imaginaryDouble1 = (ImaginaryDouble) new ImaginaryDouble().create("5.5i")
                                .add(new ImaginaryDouble().create("5.5i")); // 11.0i
                ImaginaryDouble imaginaryDouble2 = (ImaginaryDouble) new ImaginaryDouble().create("5.5i")
                                .sub(new ImaginaryDouble().create("5.5i")); // 0.0i
                ImaginaryDouble imaginaryDouble3 = (ImaginaryDouble) new ImaginaryDouble().create("5.5i")
                                .mul(new ImaginaryDouble().create("5.5i")); // -30.25
                ImaginaryDouble imaginaryDouble4 = (ImaginaryDouble) new ImaginaryDouble().create("5.5i")
                                .div(new ImaginaryDouble().create("5.5i")); // 1.0
                ImaginaryDouble imaginaryDouble5 = (ImaginaryDouble) new ImaginaryDouble().create("5.5i")
                                .pow(new ImaginaryDouble().create("5.5i")); // 1000.0i

                for (Value value : Arrays.asList(myInteger1, myInteger2, myInteger3, myInteger4, myInteger5, myDouble1,
                                myDouble2, myDouble3, myDouble4, myDouble5, imaginaryInt1, imaginaryInt2, imaginaryInt3,
                                imaginaryInt4, imaginaryDouble1, imaginaryDouble2, imaginaryDouble3, imaginaryDouble4,
                                imaginaryDouble5)) {
                        value.print();
                }
        }
}