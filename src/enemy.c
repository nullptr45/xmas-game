#include "enemy.h"

#include <raymath.h>

static void draw_enemy_health_bar(Vector2 pos, float radius, float health, float max_health, EnemyRank rank)
{
    float t = health / max_health;
    if (t < 0) t = 0;
    if (t > 1) t = 1;

    float width = radius * 2.0f;
    float height = (rank == ENEMY_RANK_BADASS) ? 6.0f : 4.0f;

    Vector2 bar_pos = {
        pos.x - width * 0.5f,
        pos.y - radius - 10.0f
    };

    DrawRectangle(
        bar_pos.x,
        bar_pos.y,
        width,
        height,
        (Color){30, 30, 30, 200}
    );

    Color fill = GREEN;
    if (t < 0.6f) fill = YELLOW;
    if (t < 0.3f) fill = RED;

    DrawRectangle(
        bar_pos.x,
        bar_pos.y,
        width * t,
        height,
        fill
    );

    DrawRectangleLines(
        bar_pos.x,
        bar_pos.y,
        width,
        height,
        BLACK
    );
}

void enemy_init(Enemy *enemy, Vector2 position, EnemyRank rank, float scale)
{
    enemy->entity.active = true;
    enemy->entity.pos = position;
    enemy->entity.radius = 10.0f;
    enemy->entity.active = true;
    enemy->entity.tint = RED;
    enemy->entity.vel = Vector2Zero();
    enemy->max_health = 100.0f;
    enemy->speed = 900.0f;
    enemy->attack_cooldown = 0.5f;
    enemy->attack_timer = 0.0f;
    enemy->rank = rank;

    switch (rank) {
        case ENEMY_RANK_WEAK:
            enemy->max_health = 20.0f;
            enemy->damage = 10.0f;
            enemy->entity.radius = 10;
            break;

        case ENEMY_RANK_NORMAL:
            enemy->max_health = 50.0f;
            enemy->damage = 15.0f;
            enemy->entity.radius = 14;
            break;

        case ENEMY_RANK_BADASS:
            enemy->max_health = 150.0f;
            enemy->damage = 20.0f;
            enemy->entity.radius = 20;
            break;
    }

    enemy->max_health *= scale;
    enemy->damage *= (0.7f + scale * 0.3f);
    enemy->speed *= (1.0f + 0.15f * logf(scale));
    enemy->health = enemy->max_health;
} 

void enemy_update(Enemy *enemy, float delta, Player *player)
{
    if (!enemy->entity.active) return;

    if (enemy->attack_timer > 0)
        enemy->attack_timer -= delta;

    static const float friction = 8;
    static const float knockback = 400;

    Vector2 dir = Vector2Subtract(player->entity.pos, enemy->entity.pos);
    float dist = Vector2Length(dir);

    if (dist > 0.01) {
        dir = Vector2Normalize(dir);
        enemy->entity.vel = Vector2Add(enemy->entity.vel, Vector2Scale(dir, enemy->speed * delta));
    }

    enemy->entity.vel = Vector2Lerp(enemy->entity.vel, Vector2Zero(), friction * delta);
    enemy->entity.pos = Vector2Add(enemy->entity.pos, Vector2Scale(enemy->entity.vel, delta));

    resolve_collision(&enemy->entity, &player->entity);

    if (dist < player->entity.radius + enemy->entity.radius && enemy->attack_timer <= 0) {
        player_take_damage(player, enemy->damage);
        Vector2 force = Vector2Normalize(Vector2Subtract(player->entity.pos, enemy->entity.pos));
        player_take_knockback(player, force, knockback);
        enemy->attack_timer = enemy->attack_cooldown;
    }
}

void enemy_render(Enemy *enemy)
{
    if (!enemy->entity.active) return;

    DrawCircleV(enemy->entity.pos, enemy->entity.radius, enemy->entity.tint);

    if (enemy->health < enemy->max_health || enemy->rank == ENEMY_RANK_BADASS) {
        draw_enemy_health_bar(
            enemy->entity.pos,
            enemy->entity.radius,
            enemy->health,
            enemy->max_health,
            enemy->rank
        );
    }
}

void enemy_take_damage(Enemy *enemy, Player *player, float damage)
{
    if (!enemy->entity.active) return;

    enemy->health -= damage;

    if (enemy->health <= 0) {
        enemy->entity.active = false;

        float xp = 0.f;
        switch (enemy->rank) {
            case ENEMY_RANK_WEAK:
                xp = 1.f;
                break;
            case ENEMY_RANK_NORMAL:
                xp = 2.f;
                break;
            case ENEMY_RANK_BADASS:
                xp = 5.f;
                break;
        }
        player_gain_xp(player, xp);
    }
}

