public class studen
{
    int id;
    String name;
    int age;

    void study()
    {
        System.out.println("我在学习！");
    }

    void play()
    {
        System.out.println("我在写代码！");
    }

    //程序执行入口
    public static void main(String[] args)
    {
        studen yuan = new studen();
        yuan.play();
    }
}