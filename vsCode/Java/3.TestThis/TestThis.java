public class TestThis
{
    int a,b,c;

    TestThis(int a,int b)
    {
        this.a = a;
        this.b = b;
    }

    TestThis(int a,int b,int c)
    {
        this(a,b);
        this.c = c;
    }

    void sing()
    {

    }

    void eat()
    {
        sing();
        System.out.println("ÕýÔÚ³Ô·¹£¡");
    }

    public static void main(String[] args)
    {
        TestThis he = new TestThis(3,4);
        he.eat();
    }
}