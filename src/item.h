#pragma once

#include <raylib.h>

#include <stdbool.h>

typedef enum {
    ITEM_TYPE_NONE,
    ITEM_TYPE_WEAPON,
    ITEM_TYPE_SHIELD,
    ITEM_TYPE_AMMO,
} ItemType;

typedef enum {
    ITEM_RARITY_COMMON,
    ITEM_RARITY_UNCOMMON,
    ITEM_RARITY_RARE,
    ITEM_RARITY_EPIC,
    ITEM_RARITY_LEGENDARY,
} ItemRarity;

typedef struct Weapon {
    float damage;
    float fire_rate;
    float reload_speed;
    float projectile_speed;
    int mag_size;
} Weapon;

typedef struct Shield {
    float capacity;
    float recharge_rate;
    float recharge_delay;
} Shield;

typedef struct Item {
    ItemType type;
    ItemRarity rarity;

    union {
        Weapon weapon;
        Shield shield;
    };
} Item;

static float rarity_multiplier(ItemRarity r)
{
    switch (r) {
        case ITEM_RARITY_COMMON:    return 1.0f;
        case ITEM_RARITY_UNCOMMON:  return 1.2f;
        case ITEM_RARITY_RARE:      return 1.5f;
        case ITEM_RARITY_EPIC:      return 2.0f;
        case ITEM_RARITY_LEGENDARY: return 3.0f;
        default: return 1.0f;
    }
}

Item item_generate_weapon(ItemRarity rarity);
Item item_generate_shield(ItemRarity rarity);

