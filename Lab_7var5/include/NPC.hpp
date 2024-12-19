#pragma once
#include <list> // для хранения списка наблюдателей
#include <memory>  // какие-то умные указатели: тут не используются
#include "observer.hpp"

class Bear;
class Thug;
class Werewolf;

class NPC
{
protected:
    std::list<Observer *> observers;  // в списке будет хранится указ-ль на объект типа Observer
    int x;
    int y;
    std::string name;
    bool alive;

public:
    NPC() = default;
    ~NPC() = default;

    virtual void print(std::ostream &) = 0;  // т.к написано = 0, то это значит, что f-ия чисто виртуальная
    // т.к поток, то по ссылке, не копировать же его
    virtual void accept(NPC *, const int &) = 0;  // передача по у-лю, чтоб не копировать, а по ссылке, чтоб не
    // копировать и не менять

    virtual void attach(Observer *);  // для регистрации наблюдателя в объекте NPC
    /*. Когда этот NPC будет изменяться (например, когда он умрет), все зарегистрированные 
    наблюдатели будут уведомлены.*/
    // Параметр: Observer *observer — указатель на объект-наблюдателя, который будет отслеживать изменения  NPC.
    virtual void detach(Observer *);  // удаление наблюдателя из списка наблюдателей NPC
    virtual void notify(NPC *, bool);  // уведомление всех зарегистрированных наблюдателей о каком-либо событии, например, смерти NPC

    virtual bool is_close(const NPC &, const int &) const noexcept;
    // Определяет, находится ли другой NPC в пределах указанной дистанции
    virtual bool is_alive() const noexcept;  // жив ли NPC

    friend std::ostream &operator<<(std::ostream &, const NPC &);  // чтобы получить доступ к атрибутам классса
};