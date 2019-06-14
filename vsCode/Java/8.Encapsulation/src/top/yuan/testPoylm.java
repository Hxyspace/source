package top.yuan;
/* 测试多态 */
public class testPoylm
{
    public static void main(String[] args) 
    {
        Animal b = new Animal();
        cry(b);
        dog d = new dog();
        cry(d);
        Animal c = new dog();   /* 自动向上转型 */
        cry(c);
        dog x = (dog)c;         /* 强制向下转型 */
        x.hello();              /* 需强制转型，才能成功调用dog内的方法 c的属性仍为Animal */
        cry(new dog());
        cry(new cat());
        
    }
    static void cry(Animal a)
    {
        a.shout();
    }
}

class Animal
{
    public void shout()
    {
        System.out.println("叫了一声！");
    }
}

class dog extends Animal
{
    public void shout()
    {
        System.out.println("汪汪汪！！");
    }
    public void hello()
    {
        System.out.println("hello");
    }
}

class cat extends Animal
{
    public void shout()
    {
        System.out.println("喵喵喵！！！");
    }
}