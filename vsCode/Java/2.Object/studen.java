public class studen
{
    int id;
    String name;
    int age;

    void study()
    {
        System.out.println("����ѧϰ��");
    }

    void play()
    {
        System.out.println("����д���룡");
    }

    //����ִ�����
    public static void main(String[] args)
    {
        studen yuan = new studen();
        yuan.play();
    }
}