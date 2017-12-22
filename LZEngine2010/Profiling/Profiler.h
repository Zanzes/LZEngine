#pragma once
#include <DataStructures/LZLinkedList.h>

using LZSoft::DataStructures::LZLinkedList;

namespace LZSoft
{
	namespace Profiling
	{
		class __declspec(dllexport) Profiler
		{
		private:
			Profiler() {};
			Profiler(const Profiler&);
			Profiler& operator=(const Profiler&);
			static Profiler pInstance;
#if PROFILING_ON
			const char* FileName;
			static const int MAX_SAMPLES = 50000;
			static const int MAX_CATEGORIES = 20;
			int Frame=-1;
			int CategoryIndex=0;
			struct Category
			{
				const char* Name;
				LZLinkedList<float> samples;
			};
			LZLinkedList<Category> categories;
#endif
		public:
			static Profiler& GetInstance();
#if PROFILING_ON
			bool Initialize(const char* filename);
			void NextFrame();
			void addEntry(const char* category, float time);
			bool Shutdown();
#else
			bool Initialize(const char* filename) { return true; };
			void NextFrame() {};
			void addEntry(const char* category, float time) {};
			bool Shutdown() { return true; };
#endif

		};
	}
}

#define profiler LZSoft::Profiling::Profiler::GetInstance()