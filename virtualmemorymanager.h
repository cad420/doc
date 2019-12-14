




class  AbstrCachePolicy : public AbstrMemoryCache
{
public:
	AbstrCachePolicy( ::vm::IRefCnt *cnt ) :
	  AbstrMemoryCache( cnt ) {}

	virtual bool QueryPage( size_t pageID ) = 0;

	virtual void UpdatePage( size_t pageID ) = 0;

	virtual size_t QueryAndUpdate( size_t pageID ) = 0;

	AbstrMemoryCache *GetOwnerCache() { return ownerCache; }

	const AbstrMemoryCache *GetOwnerCache() const { return ownerCache; }

	const void *GetPage( size_t pageID ) override { return nullptr; }

	size_t GetPageSize() const override { return 0; }

	size_t GetPhysicalPageCount() const override { return 0; }

	size_t GetVirtualPageCount() const override { return 0; }

protected:
	void *GetPageStorage_Implement( size_t pageID ) override { return nullptr; }

	virtual void InitEvent( AbstrMemoryCache *cache ) = 0;

};