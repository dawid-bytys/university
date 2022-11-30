package com.company;
import static java.lang.Math.*;

public class Main {

    public static void main(String[] args) {
        figura prost=new figura();
        prost.rodzajFigury=figura.prostokat;
        prost.a=10; prost.b=5;
        figura trojkat=new figura();
        trojkat.rodzajFigury=figura.trojkat;
        trojkat.a=4;
        trojkat.b=3;
        trojkat.c=5;
        figura kolo=new figura();
        kolo.rodzajFigury=figura.kolo;
        kolo.c=3;

        figura[] figury={trojkat,prost,kolo};
        for(int i=0;i<figury.length;i++)
        {
            figura temp=figury[i];
            switch(temp.rodzajFigury)
            {
                case figura.prostokat:
                    System.out.println("Pole prostokata wynosi "+temp.a*temp.b);
                    break;
                case figura.kolo:
                    System.out.println("Pole kola wynosi " +PI*temp.c*temp.c);
                    break;
                case figura.trojkat:
                    float p=0.5f*(temp.a+temp.b+temp.c);
                    System.out.println("Pole trojkata wynosi " +sqrt(p*(p-temp.a)*(p-temp.b)*(p-temp.c)));
                    break;
            }
        }
    }
}

class  figura
{
    final static int trojkat=1;
    final static int prostokat=2;
    final static int kolo=3;

    int rodzajFigury;

    float a; //podstawa trójkąta lub pierwszy bok prostokąta
    float b; //drugi bok prostakata lub trojkat
    float c; //promień koła lub trzeci bok trojkata
}




