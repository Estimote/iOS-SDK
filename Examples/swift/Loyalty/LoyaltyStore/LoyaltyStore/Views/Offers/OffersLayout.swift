//
// Please report any problems with this app template to contact@estimote.com
//

class OffersLayout: UICollectionViewLayout {
  
  @objc var numberOfColumns         = 3
  @objc var cellPadding: CGFloat    = 6.0
  @objc let firstRowOffset: CGFloat = 30
  
  fileprivate var cache = [UICollectionViewLayoutAttributes]()
  
  fileprivate var contentHeight: CGFloat {
    let insets = self.collectionView!.contentInset
    return self.collectionView!.bounds.height - (insets.top + insets.bottom) + firstRowOffset
  }
  
  fileprivate var contentWidth: CGFloat {
    let insets = collectionView!.contentInset
    return collectionView!.bounds.width - (insets.left + insets.right)
  }
  
  override func prepare() {
    
    if cache.isEmpty {
      
      let columnWidth = contentWidth / CGFloat.init(numberOfColumns)
      
      var xOffset = [CGFloat]()
      
      for column in 0 ..< numberOfColumns {
        xOffset.append(CGFloat.init(column) * columnWidth )
      }
      
      var column = 0
      
      let _yOffset = [CGFloat].init(repeating: 0, count: numberOfColumns)
      // add offset of 30y to the first row of cells (first 3)
      var yOffset = _yOffset.map { ((_yOffset.index(of: $0)! < numberOfColumns) ? $0 + firstRowOffset : $0) }
      
      for item in 0 ..< collectionView!.numberOfItems(inSection: 0) {
        
        // assign column based on row
        let row = Int(Float(item) / Float(numberOfColumns))
        column = item - (row * numberOfColumns)
        
        let indexPath = IndexPath(item: item, section: 0)
        
        // frame size calculation
        let height      = contentHeight / 2 - firstRowOffset
        let frame       = CGRect(x: xOffset[column], y: yOffset[column], width: columnWidth, height: height)
        let insetFrame  = frame.insetBy(dx: cellPadding, dy: cellPadding)
        
        // set frame
        let attributes   = UICollectionViewLayoutAttributes(forCellWith: indexPath)
        attributes.frame = insetFrame
        
        cache.append(attributes)
        
        yOffset[column] = yOffset[column] + height
        
        column += (column >= (numberOfColumns - 1)) ? 0 : 1
      }
    }
  }
  
  override var collectionViewContentSize : CGSize {
    return CGSize.init(width: self.contentWidth, height: self.contentHeight)
  }
  
  override func layoutAttributesForElements(in rect: CGRect) -> [UICollectionViewLayoutAttributes]? {
    
    var layoutAttributes = [UICollectionViewLayoutAttributes]()
    let offset = collectionView!.contentOffset
    
    
    let headerAttributes = self.layoutAttributesForSupplementaryView(ofKind: UICollectionElementKindSectionHeader, at: IndexPath(item: 0, section: 0))!
    
    var headerRect = headerAttributes.frame
    headerRect.origin.y = offset.y
    headerAttributes.frame = headerRect
    
    layoutAttributes.append(headerAttributes)
    
    for attributes in cache {
      if attributes.frame.intersects(rect) {
        layoutAttributes.append(attributes)
      }
    }
    
    return layoutAttributes
  }
  
  // header attributes
  override func layoutAttributesForSupplementaryView(ofKind elementKind: String, at indexPath: IndexPath) -> UICollectionViewLayoutAttributes? {
    let attributes = UICollectionViewLayoutAttributes(forSupplementaryViewOfKind: elementKind, with: indexPath)
    attributes.frame = CGRect(x: 0, y: 0, width: self.collectionView!.bounds.width, height: 30)
    
    return attributes
  }
  
  override func shouldInvalidateLayout(forBoundsChange newBounds: CGRect) -> Bool {
    return true
  }
}
