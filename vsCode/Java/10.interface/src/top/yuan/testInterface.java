/* 测试接口和实现类 */

package top.yuan;

public class testInterface
{
    public static void main(String[] args) 
    {
        Volant f = new Angel();
        f.fly();
    }
}

interface Volant
{
    int FLY_HEIGHT = 1000;
    void fly();
}

interface Honest
{
    void helpOther();
}

class Angel implements Volant,Honest        //实现类可以实现多个父接口
{
    @Override
    public void helpOther()
    {
        System.out.println("Angel.helpOther()");
    }

    @Override
    public void fly()
    {
        System.out.println("Angel.fly()");
    }
}