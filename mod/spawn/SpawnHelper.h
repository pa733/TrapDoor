//
// Created by xhy on 2020/12/31.
//

#ifndef MOD_SPAWNHELPER_H
#define MOD_SPAWNHELPER_H

#include <vector>
#include "graphics/BlockPos.h"
#include "entity/Actor.h"
#include "block/BlockLegacy.h"
#include "block/Block.h"

namespace mod {


    //这个结构的代码不要动，顺序也别动
    struct SpawnConditions {
        bool isOnSurface = false;
        bool isInWater = false;
        bool isInLava = false;
        bool isUnderground = false;
        uint32_t gap = 0;
        uint64_t delayEndWorldAge = 0;
        uint32_t rawBrightness = 0;
        trapdoor::BlockPos pos{};
    };


    struct MobSpawnRules {

    };

    struct MobSpawnData {
        MobSpawnRules *getSpawnRules();

        trapdoor::ActorDefinitionIdentifier *getActorID();
    };

    class SpawnHelper {
        std::vector<trapdoor::BlockPos> verticalSpawnPositions;
        bool enable = false;
        unsigned long long gameTick;
    public:
        inline void setAble(bool able) { this->enable = able; }

        inline bool isEnable() const { return this->enable; }

        void tick();

        void draw();

        void updateVerticalSpawnPositions(const trapdoor::BlockPos &pos, trapdoor::Actor *player);

        void printSpawnProbability(trapdoor::Actor *player, const trapdoor::BlockPos &pos, uint32_t bright);


    };

    void findNextSpawnPosition(trapdoor::BlockSource *source, trapdoor::BlockPos *pos, unsigned int material);

    MobSpawnData *
    getMobToSpawn(trapdoor::BlockLegacy *legacy, const SpawnConditions &spawnConditions,
                  trapdoor::BlockSource *blockSource);

}


#endif //MOD_SPAWNHELPER_H