package top.yuan.oo;

/* ��д(override)/�̳� */

public class override
{
    public static void main(String[] args) 
    {
        Horse ma = new Horse();
        ma.run();
    }
}

class Vehicle
{
    public void run()
    {
        System.out.println("��...");
    }

    public void stop()
    {
        System.out.println("ͣ��");
    }
}

class Horse extends Vehicle
{
    public void run()
    {
        System.out.println("������...");
    }
}