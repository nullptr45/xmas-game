#include "game.h"

#include <raymath.h>

static void spawn_projectile(Projectile *projectiles, Vector2 pos, Vector2 dir, float speed, float damage)
{
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (!projectiles[i].entity.active) {
            projectile_spawn(
                &projectiles[i],
                pos,
                Vector2Normalize(dir),
                speed,
                damage
            );
            return;
        }
    }
}

static void fire_bullet(GameData *game, Vector2 origin)
{
    Vector2 target = GetMousePosition();
    Vector2 dir = Vector2Subtract(target, origin);
    dir = Vector2Normalize(dir);

    Weapon *weapon = &game->player.equipped_weapon.weapon;
    if (game->player.shoot_timer <= 0) {
        spawn_projectile(
            game->projectiles,
            game->player.entity.pos,
            dir,
            weapon->projectile_speed,
            weapon->damage
        );

        game->player.shoot_timer = 1.0f / weapon->fire_rate;
    }
}

void game_init(GameData *game)
{
    player_init(&game->player, (Vector2){640, 360});

    for (int i = 0; i < MAX_ENEMIES; ++i) {
        enemy_init(&game->enemies[i]);
    }

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        game->projectiles[i].entity.active = false;
    }

    HideCursor();
}

void game_update(GameData *game, float delta)
{
    player_update(&game->player, delta);

    // for (int i = 0; i < MAX_ENEMIES; ++i) {
    //     enemy_update(&game->enemies[i], delta);
    // }

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        fire_bullet(game, game->player.entity.pos);
    }

    for (int i = 0; i < MAX_PROJECTILES; ++i) {
        projectile_update(&game->projectiles[i], delta);
    }
}

void game_render(GameData *game)
{
    player_render(&game->player);

    for (int i = 0; i < MAX_PROJECTILES; ++i)
        projectile_render(&game->projectiles[i]);

    Vector2 mouse = GetMousePosition();
    DrawCircleLines(mouse.x, mouse.y, 6, RED);

    // for (int i = 0; i < MAX_ENEMIES; ++i) {
    //     enemy_render(&game->enemies[i]);
    // }
}

