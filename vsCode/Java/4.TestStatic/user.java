/* ����static�ؼ��� */
public class user
{
    int id;
    String name;
    String pwd;

    static String company = "yuan55";

    public user(int id,String name)
    {
        this.id = id;
        this.name = name;
    }

    public void login()
    {
        System.out.println("��¼:" + name);
    }

    public static void printcompany()
    {
        //login();      //���÷Ǿ�̬��Ա������ᱨ��
        System.out.println(company);
    }

    public static void main(String[] args) 
    {
        user xin = new user(55,"yuan");
        System.out.println(xin.id);
        user.printcompany();
        user.company = "yuancompany";
        user.printcompany();
    }
}