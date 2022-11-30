
/*
Pobawmy się trochę z zastępowaniem nadklasy delegatem.
Powiedzmy, że tworzymy specjalny rodzaj stosu, który zawsze zwraca nam nie pierwszy a drugi element od góry.
Elementy dodawane są jak w zwykłym stosie
 */


import java.util.ArrayList;




public class Main {

    public static void main(String[] args) {
	// write your code here

        superStos X=new superStos();
        X.push("hello");
        X.push(124);
        X.push("world");
        X.push(4335);

        System.out.println(X.pop2());
        System.out.println(X.pop2());
        System.out.println(X.pop2());
        System.out.println(X.pop2());

        System.out.println("dalej");
        //wszystko jest fajnie ale nasz super stos odziedziczył mnóstwo funkcji z ArrayList zatem można z nim zrobić coś takiego jak poniżej
        X.push("hello");
        X.push(124);
        X.push("world");
        X.push(4335);

        X.clear(); ///Ale my takiej możliwości nie chcemy!!!
        System.out.println(X.pop2());
        System.out.println(X.pop2());
        System.out.println(X.pop2());
        System.out.println(X.pop2());
        //Proszę to poprawić
    }




}

class superStos extends ArrayList
{
    public void push(Object x)
    {
        this.add(x);
    }

    public Object pop2()
    {
        if(this.size()<2)
        {
            return null;
        }
        else
        {
            Object x=this.get(this.size()-2);
            this.remove(this.size()-2);
            return x;
        }
    }
}
