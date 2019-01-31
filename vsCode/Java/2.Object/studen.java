public class studen
{
    int id;
    String name;
    int age;

    Computer comp;  //计算机

    void study()
    {
        System.out.println("我在学习！");
    }

    void play()
    {
        System.out.println("我在写代码！电脑：" + comp.brand);
    }

    //程序执行入口
    public static void main(String[] args)
    {
        studen yuan = new studen();
        yuan.id = 1001;
        yuan.name = "鑫";
        yuan.age = 20;

        Computer c1 = new Computer();
        c1.brand = "联想";

        yuan.comp = c1;
        yuan.play();
    }
}

class Computer
{
    String brand;
}