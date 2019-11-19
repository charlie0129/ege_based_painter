#include "save_file.h"

int SaveFile(void)
{
	FILE* fp;
	OPENFILENAME ofn = { 0 };
	TCHAR strFilename[MAX_PATH] = { 0 };
	char c_strFilename[MAX_PATH] = { 0 };
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = TEXT("*.draw\0\0");
	ofn.nFilterIndex = 1;//过滤器索引
	ofn.lpstrFile = strFilename;
	ofn.nMaxFile = sizeof(strFilename);
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
	ofn.lpstrTitle = TEXT("画图文件另存为");
	ofn.lpstrDefExt = TEXT("draw");
	if (!(GetSaveFileName(&ofn)))
	{
		MessageBox(NULL, TEXT("请输入一个文件名"), NULL, MB_ICONERROR);
	}

	TCHARToChar(strFilename, c_strFilename);
	fp = fopen(c_strFilename, "rb+");

	fwrite(shapeData, sizeof(shapeData[0]), sizeof(shapeData) / sizeof(shapeData[0]), fp);
	fwrite(&g_nTotalShapes, sizeof(unsigned short int), 1, fp);
	fwrite(&fileValidityCheckSuffix, sizeof(fileValidityCheckSuffix), 1, fp);
	fclose(fp);
	return 0;
	
}