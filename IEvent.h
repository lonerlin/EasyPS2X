#ifndef IEVENT_H
#define IEVENT_H
#endif // IEVENT_H_INCLUDED
class IPS2XEvent
{
public:
    //���Ա����=0;��ʾ���಻�������Ա��������ʵ�֣����ó�Ա����û�к�����{ }�����ֺ����ͽд��麯����
    //һ������ֻҪ��һ����Ա�����Ǵ��麯�����ͳ��˲���ʵ���������࣬�൱�ڽӿڣ�ֻ�ܸ�������̳У��������������к���������д����鷽����
    virtual void OnPressed(int keyValue) = 0;
};
