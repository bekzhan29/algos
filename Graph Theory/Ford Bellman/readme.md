Алгоритм Форда-Беллмана находит кратчайшее расстояние от одной вершины до всех остальных за время $O(NM)$.

Данная реализация содержит оптимизацию. Если на одной из итераций не удалось сократить путь до какой-либо вершины, то алгоритм завершается. В худшем случае алгоритм будет работать $O(NM)$, но в рандомных графах время работы сократится.