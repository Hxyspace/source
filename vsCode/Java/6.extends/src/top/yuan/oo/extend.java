package top.yuan.oo;

/* 继承 */

public class extend
{
    public static void main(String[] args)
    {
        student u = new student("xin",170,"学生");
        System.out.println("姓名："+u.name+'\n'+u.height+'\n'+"职业："+u.major);
        u.rest();
    }
}

class Person
{
    String name;
    int height;

    public void rest()
    {
        System.out.println("休息 一下");
    }
}

class student extends Person
{
    String major;

    public void study()
    {
        System.out.println("学习！");
    }

    public student(String name,int height,String major)
    {
        this.name = name;
        this.height = height;
        this.major = major;
    }
}