#pragma once

#include <moveit/planning_interface/planning_interface.h>

#include <stomp_moveit_parameters.hpp>

// Forward declaration
namespace stomp
{
class Stomp;
}

namespace stomp_moveit
{
class StompPlanningContext : public planning_interface::PlanningContext
{
public:
  StompPlanningContext(const std::string& name, const std::string& group_name, const stomp_moveit::Params& params);

  bool solve(planning_interface::MotionPlanResponse& res) override;

  bool solve(planning_interface::MotionPlanDetailedResponse& res) override;

  bool terminate() override;

  void clear() override;

  planning_scene::PlanningScenePtr getStompPlanningScene() const;

  const Params &getParams() const;

private:
  const stomp_moveit::Params params_;
  std::shared_ptr<stomp::Stomp> stomp_;
  planning_scene::PlanningScenePtr planning_scene_stomp_;
};
}  // namespace stomp_moveit
