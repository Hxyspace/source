package top.yuan.oo;

/* �̳� */

public class extend
{
    public static void main(String[] args)
    {
        student u = new student("xin",170,"ѧ��");
        System.out.println("������"+u.name+'\n'+u.height+'\n'+"ְҵ��"+u.major);
        u.rest();
    }
}

class Person
{
    String name;
    int height;

    public void rest()
    {
        System.out.println("��Ϣ һ��");
    }
}

class student extends Person
{
    String major;

    public void study()
    {
        System.out.println("ѧϰ��");
    }

    public student(String name,int height,String major)
    {
        this.name = name;
        this.height = height;
        this.major = major;
    }
}