package top.xin;

import top.yuan.Human;

public class test
{
    public static void main(String[] args) 
    {
        boy x = new boy(78);
        x.hello();
    }
}

class boy extends Human
{
    
    void hello()
    {
        /* height = 19; */
        System.out.println(height);
    }

    boy(int height)
    {
        this.height = height;
    }
}