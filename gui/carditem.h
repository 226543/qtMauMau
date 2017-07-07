#ifndef CARDITEM_H
#define CARDITEM_H

#include <QWidget>
#include <gameLogic/card.h>
#include <QPixmap>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>


class CardItem {

public:
    enum specialCards {
        NOT_USED = -1,
        DEPOT = 0,
        EMPTY_TALON = 1,
        BLUE_HORIZONTAL = 2,
        BLUE_VERTICAL = 3,
        RED_VERTICAL = 4,
        RED_HORIZONTAL = 5,
    };

    CardItem();
    CardItem(const Card& _card);
    CardItem(CardItem::specialCards _specialCode);
    CardItem(const CardItem& _cardItem);
    CardItem& operator= (const CardItem & _cardItem);
    void removeImg() const;
    QGraphicsPixmapItem* getGraphicsItem() const;
    QGraphicsPixmapItem* createImg();
    specialCards getSpecialCode() const;
    //void setCard(const Card &card);
    Card getCard() const;
    void setPos(qreal _x, qreal _y);
    qreal getX() const;
    qreal getY() const;
    bool getPlayable() const;
    void setPlayable(bool value);
    ~CardItem();

private:
    std::string getSpecialCardName();
    std::string getNormalCardName();

    bool playable = false;
    std::string imgExtension;
    std::string deckNumber;
    CardItem::specialCards specialCode = specialCards::NOT_USED;
    QGraphicsPixmapItem *graphicsItem = NULL;
    qreal x = 0;
    qreal y = 0;
    Card card;

signals:

public
slots:
};

#endif // CARDITEM_H
