#pragma once
bool RouteBlind(int** maze, PosType nowpos)
{
    if (PATH == maze[nowpos.x + 1][nowpos.y] || MONSTER == maze[nowpos.x + 1][nowpos.y])
        return FALSE;
    if (PATH == maze[nowpos.x - 1][nowpos.y] || MONSTER == maze[nowpos.x - 1][nowpos.y])
        return FALSE;
    if (PATH == maze[nowpos.x][nowpos.y + 1] || MONSTER == maze[nowpos.x][nowpos.y + 1])
        return FALSE;
    if (PATH == maze[nowpos.x][nowpos.y - 1] || MONSTER == maze[nowpos.x][nowpos.y - 1])
        return FALSE;
    return TRUE;

}