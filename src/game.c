#include "game.h"
#include "ui.h"

#include <raylib.h>
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
    Vector2 target = GetScreenToWorld2D(GetMousePosition(), game->camera);
    Vector2 dir = Vector2Subtract(target, origin);
    dir = Vector2Normalize(dir);

    Weapon *weapon = &game->player.weapon.weapon;
    if (game->player.shoot_timer <= 0 && game->player.rounds > 0) {
        spawn_projectile(
            game->projectiles,
            game->player.entity.pos,
            dir,
            weapon->projectile_speed,
            weapon->damage
        );

        game->player.shoot_timer = 1.0f / weapon->fire_rate;
        game->player.rounds--;
    }

    if (game->player.rounds <= 0) {
        game->player.is_reloading = true;
        game->player.reload_timer = weapon->reload_speed;
    }
}

static void spawn_enemy(GameData *game)
{
    for (int i = 0; i < MAX_ENEMIES; ++i) {
        Vector2 spawn_pos = {
            game->player.entity.pos.x + GetRandomValue(-600, 600),
            game->player.entity.pos.y + GetRandomValue(-600, 600)
        };

        enemy_init(&game->enemies[i], spawn_pos);
        return;
    }
}

void game_init(GameData *game)
{
    player_init(&game->player, (Vector2){640, 360});

    for (int i = 0; i < MAX_ENEMIES; ++i) {
        game->enemies[i].entity.active = false;
    }

    for (int i = 0; i < MAX_PROJECTILES; i++) {
        game->projectiles[i].entity.active = false;
    }

    spawn_enemy(game);

    game->camera = (Camera2D) {
        .target = game->player.entity.pos,
        .offset = {
            GetScreenWidth() * 0.5f,
            GetScreenHeight() * 0.5f
        },
        .rotation = 0.0f,
        .zoom = 1.0f
    };

    HideCursor();
}

void game_update(GameData *game, float delta)
{
    player_update(&game->player, delta);
    game->camera.target = game->player.entity.pos;

    for (int i = 0; i < MAX_ENEMIES; ++i) {
        enemy_update(&game->enemies[i], delta, &game->player.entity);
    }

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        fire_bullet(game, game->player.entity.pos);
    }

    for (int i = 0; i < MAX_PROJECTILES; ++i) {
        projectile_update(&game->projectiles[i], delta);
    }
}

void game_render(GameData *game)
{
    BeginMode2D(game->camera);

    player_render(&game->player);

    for (int i = 0; i < MAX_PROJECTILES; ++i)
        projectile_render(&game->projectiles[i]);

    for (int i = 0; i < MAX_ENEMIES; ++i) {
        enemy_render(&game->enemies[i]);
    }

    EndMode2D();

    ui_draw(&game->player);

    Vector2 mouse = GetMousePosition();
    DrawCircleLines(mouse.x, mouse.y, 6, RED);
}

