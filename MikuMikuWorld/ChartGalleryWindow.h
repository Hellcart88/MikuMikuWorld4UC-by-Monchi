#pragma once
#include "Score.h"
#include "Rendering/Texture.h"
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

namespace MikuMikuWorld
{
	struct ChartState {
		bool isFavorite = false;
		std::string folder = "-"; 
	};

	struct GalleryItem {
		std::string filepath;
		std::string filename;
		std::string extension; 
		std::string jacketPath;
		std::string title;
		std::string artist;    
		std::string author;    
		int totalCombo = 0;    
		std::string lengthStr = "-"; 

		std::shared_ptr<Texture> texture; 
		bool isFavorite = false;
		std::string folder = "-";
	};

	class ChartGalleryWindow
	{
	private:
		bool recentLoaded = false;
		bool hasAutoScanned = false;
		int activeTab = 0;

		std::vector<std::string> searchPaths;
		char newPathBuffer[512] = "";
		bool isSearchPathsOpen = true;
		char searchQuery[256] = "";
		int currentSortMethod = 0;  // 0: タイトル, 1: アーティスト, 2: 作者, 3: コンボ

		std::unordered_map<std::string, ChartState> galleryStates;
		std::vector<std::shared_ptr<GalleryItem>> recentItems;
		std::vector<std::shared_ptr<GalleryItem>> localItems;
		std::unique_ptr<Texture> defaultIcon = nullptr;
		std::unique_ptr<Texture> appIcon = nullptr;

		std::vector<std::string> customFolders;
		
		std::string itemToDelete = "";
		bool openDeletePopup = false;

		// --- Inline Management ---
		bool isCreatingNewFolder = false;
		int editingFolderIndex = -1; // -1: Not editing, 3+: Custom folders
		char folderEditBuffer[256] = "";

		void loadGalleryData();
		void saveGalleryData();
		std::shared_ptr<GalleryItem> loadItemInfo(const std::string& filepath);
		void drawGrid(std::vector<std::shared_ptr<GalleryItem>>& itemsToDraw, const char* gridId);
		void removeDeletedItemFromLists(const std::string& filepath);
		void deleteFolder(int index);

	public:
		bool open = true;
		std::string pendingLoadScore = ""; 

		void update(const std::vector<std::string>& recentFiles);
	};
}