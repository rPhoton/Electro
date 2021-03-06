//                    ELECTRO ENGINE
// Copyright(c) 2021 - Electro Team - All rights reserved
#pragma once
#include "Core/ElectroBase.hpp"
#include <glm/glm.hpp>

namespace Electro
{
    struct DirectoryEntry
    {
        String Name;
        String Extension;
        String AbsolutePath;

        bool IsDirectory;
        Vector<DirectoryEntry> SubEntries;
    };

    class VaultPanel
    {
    public:
        VaultPanel(const void* editorLayerPtr);
        ~VaultPanel() = default;

        void OnImGuiRender(bool* show);
    private:
        void DrawPath(DirectoryEntry& entry);
        Vector<DirectoryEntry> GetFiles(const String& directory);
        void DrawImageAtMiddle(const glm::vec2& imageRes, const glm::vec2& windowRes);
    private:
        Vector<DirectoryEntry> mFiles;
        String mProjectPath;
    };
}
