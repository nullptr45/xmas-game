#include "item.h"

#include <raymath.h>

Item item_generate_weapon(ItemRarity rarity)
{
    Item item = {0};
    item.type = ITEM_TYPE_WEAPON;
    item.rarity = rarity;

    float mult = rarity_multiplier(rarity);

    item.weapon.damage = GetRandomValue(8, 12) * mult;
    item.weapon.fire_rate = GetRandomValue(3, 8) * 0.5f;
    item.weapon.projectile_speed = GetRandomValue(300, 1000);
    item.weapon.mag_size = GetRandomValue(6, 30);
    item.weapon.reload_speed = item.weapon.mag_size * 0.1f;

    return item;
}

Item item_generate_shield(ItemRarity rarity)
{
    Item item = {0};
    item.type = ITEM_TYPE_SHIELD;
    item.rarity = rarity;

    float mult = rarity_multiplier(rarity);

    item.shield.recharge_delay = GetRandomValue(2, 4);
    item.shield.capacity = GetRandomValue(50, 150) * mult;
    item.shield.recharge_rate = GetRandomValue(5, 15) * mult;

    return item;
}

