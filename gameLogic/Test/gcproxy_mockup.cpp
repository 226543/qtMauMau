#ifdef TEST
#include "gcproxy_mockup.h"

GCProxy_mockup::GCProxy_mockup()
    : GameControllerProxy(nullptr, PLAYER::NONE)
{
}

void GCProxy_mockup::playCard(const Card& card, Card::cardSuit whishedSuit)
{
    (void)(card);
    (void)(whishedSuit);
}

void GCProxy_mockup::drawCard()
{
}
#endif
