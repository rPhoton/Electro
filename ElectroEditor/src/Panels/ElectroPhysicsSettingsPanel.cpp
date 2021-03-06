//                    ELECTRO ENGINE
// Copyright(c) 2021 - Electro Team - All rights reserved
#include "ElectroPhysicsSettingsPanel.hpp"
#include "Core/ElectroVault.hpp"
#include "Physics/ElectroPhysicsEngine.hpp"
#include "UIUtils/ElectroUIUtils.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <glm/gtc/type_ptr.hpp>

namespace Electro
{
    void PhysicsSettingsPanel::Init()
    {
        auto tex = Vault::Get<Texture2D>("physx.png");
        mPhysXTextureID = tex->GetRendererID();
        mTextureDimensions[0] = tex->GetWidth();
        mTextureDimensions[1] = tex->GetHeight();
    }

    void PhysicsSettingsPanel::OnImGuiRender(bool* show)
    {
        if (!show)
            return;

        ImGui::Begin("Physics", show);
        PhysicsSettings& settings = PhysicsEngine::GetSettings();
        UI::DrawFloatControl("Fixed Timestep", &settings.FixedTimestep);
        UI::DrawFloatControl("Gravity", &settings.Gravity.y);

        static const char* broadphaseTypeStrings[] = { "Sweep and Prune", "MultiBox Pruning", "Automatic Box Pruning" };
        UI::DrawDropdown("Broadphase Type", broadphaseTypeStrings, 3, (int*)&settings.BroadphaseAlgorithm);
        if (settings.BroadphaseAlgorithm != BroadphaseType::AutomaticBoxPrune)
        {
            UI::DrawFloat3Control("World Bounds (Min)", settings.WorldBoundsMin, 120);
            UI::DrawFloat3Control("World Bounds (Max)", settings.WorldBoundsMax, 120);
            UI::DrawSlider("Grid Subdivisions", (int&)settings.WorldBoundsSubdivisions, 1, 10000);
        }

        static const char* frictionTypeStrings[] = { "Patch", "One Directional", "Two Directional" };
        UI::DrawDropdown("Friction Model", frictionTypeStrings, 3, (int*)&settings.FrictionModel);

        UI::DrawSlider("Solver Iterations", (int&)settings.SolverIterations, 1, 255);
        ImGui::PushID("Solver Iterations");
        ImGui::SameLine();
        if (ImGui::Button("Reset"))
            settings.SolverIterations = 6;
        ImGui::PopID();

        UI::DrawSlider("Solver Velocity Iterations", (int&)settings.SolverVelocityIterations, 1, 255);
        ImGui::PushID("Solver Velocity Iterations");
        ImGui::SameLine();
        if (ImGui::Button("Reset"))
            settings.SolverVelocityIterations = 1;
        ImGui::PopID();

        if (ImGui::TreeNodeEx("Configure GlobalPhysicsMaterial"))
        {
            auto& mat = PhysicsEngine::GetGlobalPhysicsMaterial();
            UI::DrawFloatControl("Static Friction", &mat.StaticFriction);
            UI::DrawFloatControl("Dynamic Friction", &mat.DynamicFriction);
            UI::DrawFloatControl("Bounciness", &mat.Bounciness);
            ImGui::TreePop();
        }

        UI::DrawImageControl(mPhysXTextureID, { mTextureDimensions[0], mTextureDimensions[1] });
        ImGui::End();
    }
}