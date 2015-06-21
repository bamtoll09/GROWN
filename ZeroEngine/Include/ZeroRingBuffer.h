#pragma once

template <typename T, UINT MaxElements>
class ZeroRingBuffer {
private:
	UINT m_Start;
	UINT m_Count;
	T m_Elements[MaxElements];

public:
	ZeroRingBuffer() : m_Start(0), m_Count(0) {

	}

	void Add(T Element) {
		m_Elements[(m_Start + m_Count) % MaxElements] = Element;

		if (m_Count < MaxElements) {
			m_Count++;
		}
		else {
			m_Start = (m_Start + 1) % MaxElements;
		}
	}

	T GetFirst()const {
		return m_Elements[m_Start];
	}

	T GetLast()const {
		return m_Elements[(m_Start + m_Count - 1) % MaxElements];
	}

	T GetCount()const {
		return m_Count;
	}

	void Reset() {
		m_Start = 0;
		m_Count = 0;
	}
};
