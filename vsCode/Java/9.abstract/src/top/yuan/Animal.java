/* 抽象类 */
/* 抽象类只能用来被继承 */

package top.yuan;

public abstract class Animal
{
    //第一：没有实现。  第二：子类必须实现   用于规范子类
    abstract public void shout();

    public void run()
    {
        System.out.println("跑~");
    }
}

class Dog extends Animal
{
    @Override
    public void shout()
    {
        System.out.println("汪~");
    }
}