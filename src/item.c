#include "item.h"
#include "utils.h"

Item item_generate_weapon(ItemRarity rarity)
{
    Item item = {0};
    item.type = ITEM_TYPE_WEAPON;
    item.rarity = rarity;

    float mult = rarity_multiplier(rarity);

    item.weapon.damage = randint(8, 12) * mult;
    item.weapon.fire_rate = randint(3, 8) * 0.5f;
    item.weapon.reload_speed = randint(10, 30) * 0.1f;
    item.weapon.projectile_speed = randint(35, 200);
    item.weapon.mag_size = randint(6, 30);

    return item;
}

Item item_generate_shield(ItemRarity rarity)
{
    Item item = {0};
    item.type = ITEM_TYPE_SHIELD;
    item.rarity = rarity;

    float mult = rarity_multiplier(rarity);

    item.shield.capacity = randint(20, 50) * mult;
    item.shield.recharge_rate = randint(5, 15) * mult;
    item.shield.recharge_delay = randint(1, 4);

    return item;
}

