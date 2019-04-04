package top.yuan;

public class Testobject
{
    public static void main(String[] args) 
    {
        Testobject to = new Testobject();
        System.out.println(to.toString());

        person yuan = new person("xin",20);
        System.out.println(yuan.toString());
    }

    
    public String toString()
    {
        return "测试object方法";
    }
}

class person
{
    String name;
    int age;

    public String toString()
    {
        return name + "年龄:" + age;
    }

    public person(String name, int age)
    {
        this.name = name;
        this.age = age;
    }
}
