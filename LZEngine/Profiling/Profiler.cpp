#include "Profiler.h"
#include <DataStructures/Node.h>
#include <fstream>

namespace LZSoft
{
	namespace Profiling
	{
		Profiler Profiler::pInstance;
		Profiler& Profiler::GetInstance() { return pInstance; }

#ifdef PROFILING_ON

		using std::ofstream;
		using DataStructures::Node;

		bool Profiler::Initialize(const char* filename)
		{
			FileName = filename;

			bool error = true;
			error &= FileName == filename;
			error &= Frame == -1;
			error &= CategoryIndex == 0;

			return error;
		}

		void Profiler::addEntry(const char* category, const float time)
		{
			Node<Category>* n = categories.Head;
			for (int i = 0; i < CategoryIndex; i++)
				if (strcmp(n->value.Name, category) == 0)
				{
					n->value.samples.Add(time);
					if (Frame >= MAX_SAMPLES)
					{
						n->value.samples.RemoveTail();
						Frame--;
					}
					return;
				}
				else
					n = n->previous;

			Category cat;
			cat.Name = category;
			cat.samples.Add(time);
			categories.Add(cat);
			CategoryIndex++;
		}

		bool Profiler::Shutdown()
		{
			try
			{
				ofstream oFile;
				oFile.open(FileName, std::ios::out | std::ios::trunc);

				oFile << "Index, ";
				Node<Category>* cat = categories.Tail;
				for (int j = 0; j < CategoryIndex; j++)
				{
					oFile << cat->value.Name;
					(j != CategoryIndex - 1) ? oFile << ", " : oFile << std::endl;
					cat = cat->next;
				}

				for (int i = 0; i < Frame; i++)
				{
					oFile << i << ", ";
					for (int j = 0; j < CategoryIndex; j++)
					{
						Node<Category>* c = categories.AtIndex64(j);
						const LZLinkedList<float> s = c->value.samples;
						oFile << (s.Count > i ? c->value.samples.AtIndex64(i)->value : -1.f);
						(j != CategoryIndex - 1) ? oFile << ", " : oFile << std::endl;
					}
				}
				oFile.close();
				/*for (const Category& c : categories) {
				oFile << c.Name;
				}*/				
			}
			catch (...)
			{
				return false;
			}
			return true;
		}

		void Profiler::NextFrame()
		{
			Frame++;
		}
#endif


	}
}
