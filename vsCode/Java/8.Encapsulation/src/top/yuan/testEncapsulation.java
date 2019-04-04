package top.yuan;

/* 测试封装 */

public class testEncapsulation
{
    public static void main(String[] args) 
    {
        Human h = new Human();
        h.sayAge();
    }
}

class Human
{
    private int age;
    String name;

    void sayAge()
    {
        System.out.println(age);
    }
}