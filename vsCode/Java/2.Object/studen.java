public class studen
{
    int id;
    String name;
    int age;

    Computer comp;  //�����

    void study()
    {
        System.out.println("����ѧϰ��");
    }

    void play()
    {
        System.out.println("����д���룡���ԣ�" + comp.brand);
    }

    //����ִ�����
    public static void main(String[] args)
    {
        studen yuan = new studen();
        yuan.id = 1001;
        yuan.name = "��";
        yuan.age = 20;

        Computer c1 = new Computer();
        c1.brand = "����";

        yuan.comp = c1;
        yuan.play();
    }
}

class Computer
{
    String brand;
}