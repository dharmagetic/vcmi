/*
 * Heal.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */

#pragma once

#include "StackEffect.h"
#include "../../GameConstants.h"

namespace spells
{
namespace effects
{

class Heal : public StackEffect
{
public:
	Heal(const int level);
	virtual ~Heal();

	void apply(const PacketSender * server, RNG & rng, const Mechanics * m, const BattleCast & p, const EffectTarget & target) const override;
	void apply(IBattleState * battleState, const Mechanics * m, const BattleCast & p, const EffectTarget & target) const override;

protected:
	bool isValidTarget(const Mechanics * m, const battle::Unit * unit) const override;
	void serializeJsonEffect(JsonSerializeFormat & handler) override final;

private:
    EHealLevel healLevel;
	EHealPower healPower;

	int32_t minFullUnits;
};

} // namespace effects
} // namespace spells
